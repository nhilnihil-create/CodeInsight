#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int NN=N;
    int f=0;
    while(NN!=0) {
        int tmp;
        tmp=NN%10;
        f+=tmp;
        NN-=tmp;
        NN/=10;
    }
    if (N%f==0) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}