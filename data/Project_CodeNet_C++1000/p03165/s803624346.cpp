#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include<algorithm>
using namespace std;
vector<char> s;
int dp[3001][3001];


void printLcs(string x,string y,int m,int n){
     for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
     }
    //int dp[m+1][n+1];
    //vector<string> s;
       
                    //cout<<x[i-1];
                    //cout<<ch;
                    //s.push_back(x[i-1]);
                  
          int i=m;
        int j=n;
        
        while(i>0&&j>0){
               
                if(x[i-1]==y[j-1]){
                    //cout<<x[i-1];
                    //cout<<ch;
                    s.push_back(x[i-1]);
                    i--;
                    j--;

                }
                else{
                    if(dp[i][j-1]>=dp[i-1][j]){
                        j--;
                    }
                    else{
                        i--;
                    }
                }
        }
            
        
        reverse(s.begin(),s.end());
        for(auto x: s){
            cout<<x;
        }
        
    }
            
        
       // reverse(s.begin(),s.end());
        //for(auto x: s){
           // cout<<x;
        //}
        
        
    

int main() {
   string x;
   string y;
   cin>>x;
   cin>>y;
   int m=x.length();
   int n=y.length();
   printLcs(x,y,m,n);
}
