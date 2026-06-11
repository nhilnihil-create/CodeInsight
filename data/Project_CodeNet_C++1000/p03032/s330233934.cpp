#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;
#define N 100009
#define mod 1000000007

int main(){
    int n,k;
    cin>>n>>k;
    long data[n+1];
    for (int i=1; i<=n; i++) cin>>data[i];
    
    
    ll sum_left[n+1],sum_right[n+1];
    sum_left[0]=0;
    sum_right[0]=0;
    for (int i=1; i<=n; i++) sum_left[i]=sum_left[i-1]+data[i];
    for (int i=1; i<=n; i++) sum_right[i]=sum_right[i-1]+data[n+1-i];
    
    ll sum[n+1][n+1];
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++) sum[i][j]=-10000000000000;
    }
    
    vector<ll> ans;
    int count=0;
    if (n>=k){
        for (int i=0; i<=k; i++){
            for (int j=0; j<=k-i; j++){
                vector<ll> data1;
                for (int p=1; p<=i; p++) data1.push_back(data[p]);
                for (int p=1; p<=j; p++) data1.push_back(data[n-p+1]);
                sort(data1.begin(),data1.end());
                sum[i][j]=sum_left[i]+sum_right[j];
                count+=1;
                int p=min(k-i-j,i+j);
                for (int h=0; h<p; h++){
                    if (data1[h]>=0) break;
                    sum[i][j]-=data1[h];
                }
                ans.push_back(sum[i][j]);
            }
        }
        ll max=-10000000000000;
        for (int i=0; i<count; i++){
            if (max<ans[i]) max=ans[i];
        }
        cout<<max<<endl;
    }
    
    else{ //n<k
        for (int i=0; i<=n; i++){
            for (int j=0; j<=n-i; j++){
                vector<ll> data1;
                for (int p=1; p<=i; p++) data1.push_back(data[p]);
                for (int p=1; p<=j; p++) data1.push_back(data[n-p+1]);
                sort(data1.begin(),data1.end());
                data1.push_back(0);
                sum[i][j]=sum_left[i]+sum_right[j];
                count+=1;
                int p=min(k-i-j,i+j);
                for (int h=0; h<p; h++){
                    if (data1[h]>=0) break;
                    sum[i][j]-=data1[h];
                }
                ans.push_back(sum[i][j]);
            }
        }
        ll max=-10000000000000;
        for (int i=0; i<count; i++){
            if (max<ans[i]) max=ans[i];
        }
        cout<<max<<endl;
    }
}