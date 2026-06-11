#include <iostream>
using namespace std;


string s;

long int N, q;
char t[200010];
bool d[200010];
int se(long int n);
long int nibunl(long int l, long int r);
long int nibunr(long int l, long int r);
int main(){
	char d0;
	
	long int ansl=0,ansr=0;
	cin >> N>>q;
	cin >> s;
	for (int i = 0; i < q; i++) {
		cin >> t[i] >> d0;
		if (d0 == 'L')d[i] = true;
	}
	if (se(0) == N){cout << "0" << endl; return 0;}
	if (se(N - 1) == -1){cout << "0" << endl; return 0;}
	ansl = nibunl(0, N - 1);
	ansr = nibunr(0, N - 1);
	cout <<  - ansl + ansr-1 << endl;

return 0;
}
long int nibunl(long int l, long int r) {
  
	if (l == r)return l;
	if (se(l) == -1) {
		if (se(r) == -1)return nibunl(r, (3 * r - l + 1) / 2);
		else return nibunl(l, (r + l) / 2);
	}
	else return -1;
}
long int nibunr(long int l, long int r) {
    
	if (l == r)return l;
	if (se(r) == N) {
		if (se(l) == N)return nibunr((3 * l - r - 1)/ 2, l);
		else return nibunr((r + l + 1) / 2, r);
	}
	else return N;
}

int se(long int n) {
	for (long int i = 0; i < q; i++) {
		if (s[n] == t[i]) {
			if (d[i])n--;
			else n++;
			if (n == N)return N;
			if (n == -1)return -1;
	}
	}
	return 0;
}