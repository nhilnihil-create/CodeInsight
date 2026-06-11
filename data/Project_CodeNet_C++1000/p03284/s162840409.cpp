#include <iostream>

using namespace std;

int main()
{
    int N,K,large=0,small=0;
    cin >> N >> K;
    while (N-K>=0){
        N=N-K;
        large+=1;
        small+=1;
    }
    if (N>0){
        large+=1;
    }
    cout << large-small;
    return 0;
}
