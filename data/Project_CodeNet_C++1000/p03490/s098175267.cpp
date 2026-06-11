#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

int dp[2][20020];
const int c=10000;

int main(){
    string s; cin >> s;
    int n=s.size();
    int x,y; cin >> x >> y;
    int first=0;
    for(int i=0;i<n;i++){
        if(s[i]=='F'){
            while(i<n&&s[i]=='F'){
                i++;
            }
            first=i;
            break;
        }
        else break;
    }
    vector<int> nx,ny;
    int now=0;
    for(int i=first;i<n;i++){
        if(s[i]=='T')now^=1;
        else if(s[i]=='F'){
            int cnt=0;
            while(i<n&&s[i]=='F'){
                i++;
                cnt++;
            }
            i--;
            if(now==0)nx.push_back(cnt);
            else ny.push_back(cnt);
        }
    }
    dp[0][c+first]=1;
    for(int ax:nx){
        for(int i=0;i<20020;i++){
            dp[1][i]=0;
        }
        for(int i=0;i<20020;i++){
            if(dp[0][i]){
                dp[1][i+ax]=1;
                dp[1][i-ax]=1;
            }
        }
        for(int i=0;i<20020;i++){
            dp[0][i]=dp[1][i];
        }
    }
    if(dp[0][c+x]==0){
        cout << "No" << endl;
        return 0;
    }
    for(int i=0;i<20020;i++){
        dp[0][i]=0;
    }
    dp[0][c]=1;
    for(int ay:ny){
        for(int i=0;i<20020;i++){
            dp[1][i]=0;
        }
        for(int i=0;i<20020;i++){
            if(dp[0][i]){
                dp[1][i+ay]=1;
                dp[1][i-ay]=1;
            }
        }
        for(int i=0;i<20020;i++){
            dp[0][i]=dp[1][i];
        }
    }
    if(dp[0][c+y]==0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}