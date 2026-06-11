#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    if(N%2==0)N--;
    int count1=0;
    while(N>=105){
        int count0=0;
        for(int i=1;i<=N/2;i++)count0+=(N%i==0);
        count1+=(count0==7);
        N-=2;
    }
    cout << count1 << endl;
}
