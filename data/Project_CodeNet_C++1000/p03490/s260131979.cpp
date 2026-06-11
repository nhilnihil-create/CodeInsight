#include<bits/stdc++.h>
using namespace std;

string S;
long long x, y;

vector<long long> yoko;
vector<long long> tate;
#define OFFSET 10000
bool yokodp[20000];
bool yokodpnext[20000];
bool tatedp[20000];
bool tatedpnext[20000];

int main(){
	cin >> S;
	cin >> x >> y;

	long long firstmove = 0;
	long long move = 0;
	bool firstflag = true;
	bool yokoflag = false;

	for(long long i = 0; i < S.size(); i++){
		if(firstflag){
			if(S[i] == 'F'){
				firstmove++;
			}else{
				firstflag = false;
			}
		}else{
			if(yokoflag){
				if(S[i] == 'F'){
					move++;
				}else{
					yoko.push_back(move);
					move = 0;
					yokoflag = false;
				}
			}else{
				if(S[i] == 'F'){
					move++;
				}else{
					tate.push_back(move);
					move = 0;
					yokoflag = true;
				}
			}
		}
	}


	if(yokoflag){
		yoko.push_back(move);
	}else{
		tate.push_back(move);
	}

	yokodp[OFFSET + firstmove] = true;

	for(long long i = 0; i < yoko.size(); i++){
		//cout << "yoko[" << i << "]=" << yoko[i] << endl;
		for(long long j = 0; j < 20000; j++){
			if(yokodp[j]){
				yokodpnext[j + yoko[i]] = true;
				yokodpnext[j - yoko[i]] = true;
			}
		}
		for(long long j = 0; j < 20000; j++){
			yokodp[j] = yokodpnext[j];
			yokodpnext[j] = false;
		}
	}


	tatedp[OFFSET] = true;

	for(long long i = 0; i < tate.size(); i++){
		//cout << "tate[" << i << "]=" << tate[i] << endl;
		for(long long j = 0; j < 20000; j++){
			if(tatedp[j]){
				tatedpnext[j + tate[i]] = true;
				tatedpnext[j - tate[i]] = true;
			}
		}
		for(long long j = 0; j < 20000; j++){
			tatedp[j] = tatedpnext[j];
			tatedpnext[j] = false;
		}
	}

	if(yokodp[OFFSET + x] && tatedp[OFFSET + y]){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}