#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int N;
    cin >> N;
    vector<int> n_vec;
    //map<string,int> n_map;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a ;
        n_vec.push_back(a);
    }

    sort(n_vec.begin(), n_vec.end(),greater<int>());

    int a_sum = 0;
    int b_sum = 0;

    for (int i = 0; i < n_vec.size(); i++) {
        //cout << n_vec.at(i) << endl;
        if(i % 2 == 0){
            a_sum += n_vec.at(i);
        }else{
            b_sum += n_vec.at(i);
        }
    }

    cout << a_sum - b_sum << endl;

    
}
