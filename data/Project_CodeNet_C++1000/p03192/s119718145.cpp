#include <iostream>
#include <string>
using namespace std;

int main()
{
    string N;
    cin >> N;
    int count = 0;
    for(int i = 0; i < N.size(); i++) {
        if(N[i] == '2') {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}