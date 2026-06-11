#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
using namespace std::chrono;
long long int p=1e9 +7;
int n;
bool compatibility[21][21];
ll ans[21][1ll<<21];
ll solve(int N,int left){
    ll currans=0;//initialise with 0
    if(ans[N-1][left]!=-1){//check if we have already found the answer
        return ans[N-1][left];
    }
    if(N==1){
        for(int j=0;j<n;j++){
            int x=1<<j;
            if(left & x){//check if the jth women is left
                if(compatibility[N-1][j]){ 
                    ans[N-1][left]=1;
                    return 1;//If they are compatible return 1
                }
                else{
                    ans[N-1][left]=0;
                    return 0;//If the last 2 aren't compatible return 0
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(left & (1ll<<i)){//If the ith women is left
            if(compatibility[N-1][i]){//If the 2 are compatible
            currans+=solve(N-1,left - (1ll<<i));
            //Find the number of pairs after pairing them
            //and add all of them
            }
        }
    }
    currans%=p;//mod p
    ans[N-1][left]=currans;//memoise
    return ans[N-1][left];
}
ll solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1ll<<n);j++){
            ans[i][j]=-1;//memoisation initialisation
            //ans[i][j] represents i people left and
            //j is the bitmask for women left
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>compatibility[i][j];
        }
    }
    return solve(n,(1<<n)-1);//all men available, all women available because all bits set in mask
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout<<solve()<<"\n";
}
