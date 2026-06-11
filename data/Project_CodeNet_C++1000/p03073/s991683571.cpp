#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

int main(){
    string s;
    cin>>s;
    int slen=s.size();
    int ansa=0,ansb=0;
    rep(i,slen){
        if(i%2==0){
            if(s[i]!='0')ansa++;
            else ansb++;
        }else{
            if(s[i]!='0')ansb++;
            else ansa++;
        }
    }
    cout<<min(ansa,ansb)<<endl;
}