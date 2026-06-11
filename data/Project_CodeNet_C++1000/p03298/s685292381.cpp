#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

#define LL long long
map<pair<string,string>,LL> Hash;
string S;
LL Ans=0;
int N;

int main(){
    scanf("%d",&N);
    cin>>S;
    for(register int i=0;i<(1<<N);++i){
        string a,b;
        for(register int pos=1,k=1;pos<(1<<N);pos<<=1,++k){
            if(i&pos) a.push_back(S[2*N-k]);
            else b.push_back(S[2*N-k]);
        }
        Hash[make_pair(a,b)]++;
    }
    for(register int i=0;i<(1<<N);++i){
        string a,b;
        for(register int pos=1,k=1;pos<(1<<N);pos<<=1,++k){
            if(i&pos) a.push_back(S[k-1]);
            else b.push_back(S[k-1]);
        }
        Ans+=Hash[make_pair(a,b)];
    }
    cout<<Ans<<endl;
    //system("pause");
    return 0;
}