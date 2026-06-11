#include <bits/stdc++.h>


using namespace std;

#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


void go(){
	string n;cin>>n;
	int a=n[0]-'0',b=n[1]-'0',c=n[2]-'0',d=n[3]-'0';
	if(a+b+c+d==7) cout << n[0]<<'+'<<n[1]<<'+'<<n[2]<<'+'<<n[3]<<"=7";
	else if(a-b+c+d==7) cout << n[0] <<'-'<<n[1]<<'+'<<n[2]<<'+'<<n[3]<<"=7";
	else if(a+b-c+d==7) cout << n[0]<<'+'<<n[1]<<'-'<<n[2]<<'+'<<n[3]<<"=7";
	else if(a+b+c-d==7) cout << n[0]<<'+'<<n[1]<<'+'<<n[2]<<'-'<<n[3]<<"=7";
	else if(a-b-c+d==7) cout << n[0]<<'-'<<n[1]<<'-'<<n[2]<<'+'<<n[3]<<"=7";
	else if(a-b-c-d==7) cout << n[0]<<'-'<<n[1]<<'-'<<n[2]<<'-'<<n[3]<<"=7";
	else if(a-b+c-d==7) cout << n[0]<<'-'<<n[1]<<'+'<<n[2]<<'-'<<n[3]<<"=7";
	else if(a+b-c-d==7) cout << n[0]<<'+'<<n[1]<<'-'<<n[2]<<'-'<<n[3]<<"=7";
}
int main(){
   
   fastio();
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}


