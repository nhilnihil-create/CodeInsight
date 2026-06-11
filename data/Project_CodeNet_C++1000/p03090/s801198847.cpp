#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
const int mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
#define F first 
#define S second
#define PB push_back 
#define MP make_pair
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;
using vl=vector<long long>;
using vp =vector<pair<int,int>>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int main(){
    int N;
    cin >>N;
    int M;
    if(N%2==0){
        M =N*(N-2)/2;
        cout <<M<<endl;
        rep2(i,1,N){
            rep2(j,i+1,N+1){
                if(i+j==N+1) continue;
                cout << i<<" "<<j<<endl;
            }   
        }
    }
    else{
        M =(N-1)*(N-1)/2;
        cout <<M<<endl;
        rep2(i,1,N){
            rep2(j,i+1,N+1){
                if(i+j==N) continue;
                cout << i<<" "<<j<<endl;
            }   
        }
    }
}