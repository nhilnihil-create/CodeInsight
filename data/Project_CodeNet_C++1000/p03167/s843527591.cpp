#include<bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp map<int,int>
#define pp make_pair
#define endl "\n"
#define vi vector<int>
#define vbl vector<bool>
#define ll long long 
#define clock high_resolution_clock::now()

// auto duration = duration_cast<microseconds>(stop - start);  cout<<duration.count();

const int INF = 1e9+5;
const int mod = 1e9 + 7;

using namespace std;
using namespace std::chrono;

const int mx = 1005;

char arr[mx][mx];

void add_self(int&a, int b){
    a+=b;
    if(a>=mod)a-=mod;
}


int main(){
    int h, w;
    cin>>h>>w;
    for(int row =0; row<h; row++){
        cin>>arr[row];
    }
    vector<vector<int>>dp(h, vector<int>(w));
    dp[0][0] = 1;
    for(int row = 0; row<h; row++){
        for(int col = 0; col<w; col++){
            for(int r : {row, row+1}){
                int c = col;
                if(r==row){
                    c = col+1;
                }
                if(r<h && c<w && arr[r][c]=='.'){
                    add_self(dp[r][c], dp[row][col]);
                }
            }
        }
    }
    cout<<dp[h-1][w-1]<<endl;
    

	return 0;
}
	
	
