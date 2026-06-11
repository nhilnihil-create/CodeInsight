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
    int x=0,y=0;
    x=10*(s[0]-'0')+(s[1]-'0');
    y=10*(s[2]-'0')+(s[3]-'0');
    if(x>=1&&x<=12){
        if(y>=1&&y<=12){
            cout<<"AMBIGUOUS"<<endl;
        }else{
            cout<<"MMYY"<<endl;
        }
    }else{
        if(y>=1&&y<=12){
            cout<<"YYMM"<<endl;
        }else{
            cout<<"NA"<<endl;
        }
    }
}