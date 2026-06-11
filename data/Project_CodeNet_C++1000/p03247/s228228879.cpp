#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int N;
int X[1010],Y[1010];
ll x[1010] = {1},y[1010] = {1};

char mode(int n,int m){
	if(n && m) return 'R';
	if(!n && !m) return 'L';
	if(!n && m) return 'D';
	if(n && !m) return 'U';
}

int main(){
	cin >> N;
	int sum = 0;
	bool judge = true;
	for(int i=0;i<N;i++){
		cin >> X[i] >> Y[i];
		if(i==0) sum = abs(X[i])+abs(Y[i]);
		else if(sum%2!=(abs(X[i])+abs(Y[i]))%2) judge = false;
	}
	if(!judge){
		cout << -1 << endl;
		return 0;
	}
	int count = 1;
	for(int i=1;i<=32;i++){
		x[i] = 2*x[i-1];
		count++;
	}
	vector<int> d;
	if(sum%2==0) d.push_back(1);
	for(int i=0;i<=30;i++){
		d.push_back(x[i]);
	}
	cout << d.size() << endl;
	for(int i=0;i<d.size();i++){
		cout << d[i] << (i!=d.size()-1? " ":"\n");
	}
	for(int i=0;i<N;i++){
		int u = X[i]+Y[i],v = X[i]-Y[i],x = 0,y = 0,a = d.size()-1;
		string S = "";
		while(a>=0){
			int x1 = 0,y1 = 0;
			x1 = (x<=u? 1:0);
			x = (x<=u? x+d[a]:x-d[a]);
			y1 = (y<=v? 1:0);
			y = (y<=v? y+d[a]:y-d[a]);
			S = mode(x1,y1) + S;
			a--;
		}
		cout << S << endl;
	}	
}