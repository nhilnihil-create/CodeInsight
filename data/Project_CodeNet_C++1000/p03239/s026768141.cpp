#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define vi vector<int>
#define mi map<int,int>
#define mc map<char,int>

//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     int n,T,c;
     cin>>n>>T;
     vi A(n),B(n),C;
     for(int i=0;i<n;i++){
		 cin>>A[i]>>B[i];
		 }
		 for(int i=0;i<n;i++){
			 if(B[i]<=T){
				 C.push_back(A[i]);
				 }
			 }
			 c=*min_element(C.begin(),C.end());
			 if(C.size()==0){cout<<"TLE" <<"\n";}
			 else{cout<<c <<"\n";}
}
