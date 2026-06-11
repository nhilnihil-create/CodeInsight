#include <iostream>
#include <stdlib.h>
#define llint long long

using namespace std;

llint n;
llint x[1005], y[1005];
bool upos[35], vpos[35];

void calc(llint u, llint v)
{
	llint t = (u + (1LL<<31) - 1) / 2;
	for(int j = 0; j < 31; j++){
		if(t%2) upos[j] = true;
		else upos[j] = false;
		t /= 2;
	}
	t = (v + (1LL<<31) - 1) / 2;
	for(int j = 0; j < 31; j++){
		if(t%2) vpos[j] = true;
		else vpos[j] = false;
		t /= 2;
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	for(int i = 1; i <= n; i++){
		if(abs(x[i]+y[i])%2 != abs(x[1]+y[1])%2){
			cout << -1 << endl;
			return 0;
		}
	}
	
	bool odd = (abs(x[1]+y[1])%2==1);
	int m = 31; if(!odd) m++;
	
	if(odd){
		cout << 31 << endl;
		for(int i = 0; i < 31; i++) cout << (1<<i) << " "; cout << endl;
	}
	else{
		cout << 32 << endl;
		for(int i = 0; i < 31; i++) cout << (1<<i) << " "; 
		cout << 1 << endl;
	}
	
	const llint C = (1LL<<31)-1;
	for(int i = 1; i <= n; i++){
		llint u = x[i]+y[i], v = x[i]-y[i];
		if(odd) calc(u, v);
		else{
			if(u-1 > -C) upos[31] = true, u--;
			else upos[31] = false, u++;
			if(v-1 > -C) vpos[31] = true, v--;
			else vpos[31] = false, v++;
			calc(u, v);
		}
		
		for(int j = 0; j < m; j++){
			if(upos[j]){
				if(vpos[j]) cout << 'R';
				else cout << 'U';
			}else{
				if(vpos[j]) cout << 'D';
				else cout << 'L';
			}
		}
		cout << endl;
	}
	
	
	
	return 0;
}