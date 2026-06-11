#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int L;
int N,M;
int main() {
    cin>>L;

    int tmp=L;
    int len=0;
    vector<int> bitpos;
    while(tmp>0) {
        if(tmp&1) bitpos.push_back(len);
        tmp/=2;
        len++;
    }
    reverse(bitpos.begin(), bitpos.end());

    N=len;
    M=2*(len-1)+bitpos.size()-1;

    cout<<N<<" "<<M<<endl;
    for(int i=1;i<=N-1;i++) {
        cout<<i<<" "<<i+1<<" "<<(1<<(N-1-i))<<endl;
        cout<<i<<" "<<i+1<<" "<<0<<endl;
    }

    int d = (1<<N-1);
    for(int i=1;i<bitpos.size();i++) {
        int pos = bitpos[i];
        cout<<1<<" "<<N-pos<<" "<<d<<endl;
        d+=(1<<pos);
    }
}
