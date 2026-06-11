#include  <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(int a,int b){
        return a>b;
}


int  main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Insert code
    int n,h,w;
 	cin>>n>>h>>w;
  	cout<<(n-h+1)*(n-w+1);
    //End code


    cerr << "\nTime elapsed: " << 1000*clock() / CLOCKS_PER_SEC << "ms\n";
    
}