#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
std::ostream & operator<<(std::ostream & os, std::vector<T> vec)
{
    os<<"{ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
    os<<"}";
    return os;
}

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector <vector<int>> count(26, vector <int>(N + 1, 0));
    for(int i = 1 ; i <= N ; ++i){
        ++count[S[i - 1] - 'a'][i];
        for(int j = 0 ; j < 26 ; ++j){
            count[j][i] += count[j][i - 1];
        }
    }
    // for(int i = 0 ; i < 26 ; ++i){
    //     cout << "i = " << i <<  count[i] << '\n';
    // }
    int maximum = 0;
    for(int i = 1 ; i <= N ; ++i){
        // cut at position i
        // X - [1...i], Y - [i + 1...N]
        int counter = 0;
        //cout << "========> cutting at position i = " << i << '\n';
        for(int j = 0; j < 26 ; ++j){
            int left = count[j][i];
            int right = count[j][N] - left;
            if(left > 0 && right > 0){
                ++counter;
            }
            //cout << "char = " << (char)('a' + j) << " left = " << left << " right = " << right << " counter = " << counter << '\n';
        }
        //cout << "final counter = " << counter << '\n';
        maximum = max(maximum, counter);
    }
    cout << maximum << '\n';
    return 0;
}
