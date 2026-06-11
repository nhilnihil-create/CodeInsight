#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#define pb push_back
#define ll long long
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(),(x).end()
#define sqr ((x)*(x))
#define y0 y3487465
#define y1 y8687969
using namespace std;
int a,b; 
int main(){
	cin>>a>>b;
	if(a+b==15) 
   	cout<<"+";
	else if(a*b==15) 
   	cout<<"*";
	else if(a+b!=15&&a*b!=15) 
   	cout<<"x";
system ("pause");
return 0;
}

