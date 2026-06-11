#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
int main(){
    int H,W,h,w;
    cin>>H>>W>>h>>w;
    cout<<H*W-W*h-H*w+h*w<<endl;
}