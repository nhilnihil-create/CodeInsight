#include <iostream>
 
#include <deque>
 
#include <stdio.h>
 
#include <cstdio>
 
#include <algorithm>
 
#include<bits/stdc++.h>
 
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define sp <<" "
#define nw <<"\n"
#define ca "Case "<<tc++<<": "
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define ull unsigned LL
#define check cout<<"* ";
#define show_vector for(int q=0;q<v.size();q++){cout<<v[q]<<" ";}
#define REP(i,n) for (int i=0;i<(n);++i)
#define N_MAX 26
 
 
const int inf=1<<30;
const long long int INF=1e10;
const int MOD=1e9+7;
const int maxn = 1e5+10;
int a[200005],b[1000005];
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
/*
int ck_prime(int n)
{
    int coun;
     coun=0;
     if(n>1){
      for(int i=2;i*i<=n;i++){
        if( n%i==0 ){
            coun++;
            break;
          }
        }
      }
     if(n==1){
       coun=coun;
         }
    if(coun==0){
           return 1; // n is prime
        }
    return 0;
}
*/
int main()
{
    char c;
    cin>>c;
    switch(c){
       case 'A':
           cout<<"T" nw;
           break;
       case 'T':
            cout<<"A" nw;
            break;
       case 'C':
            cout<<"G" nw;
            break;
       case 'G':
            cout<<"C" nw;
            break;
    }
}
 