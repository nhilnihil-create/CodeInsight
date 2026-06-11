#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#define ll long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define vi vector<ll>
#define el printf("\n")
#define s second
#define pb(x) push_back(x)
#define f first
using namespace std;
int main(){
       ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(30);
        IOS;

  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  if(abs(c-a)<=d)
    cout <<"Yes";
  else
  {
    if(abs(a-b)<=d && abs(b-c)<=d)
    	cout << "Yes";
    else
       cout <<"No";

  }



        return 0;
    }
