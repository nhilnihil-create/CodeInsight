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

const double PI=(acos(-1));

int main(){
    char b;
    cin>>b;
    char ans;
    switch(b){
        case 'A':
            ans='T';
            break;
        case 'C':
            ans='G';
            break;
        case 'G':
            ans='C';
            break;
        case 'T':
            ans='A';
            break;
    }
    cout<<ans<<endl;
}
