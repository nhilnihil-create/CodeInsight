#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, N_max=0, M_max=0, max;
    cin >> N;
  	vector<string> N_s(N);  
  	for(int i=0;i<N;i++){
    	cin >> N_s.at(i);
    }
  	cin >> M;
  	vector<string> M_t(M);
  	for(int i=0;i<M;i++){
    	cin >> M_t.at(i);
    }
  	for(int i=0;i<N;i++){//
      	int cnt = 0;
		for(int j=0;j<N;j++){//
        	if(N_s.at(i)==N_s.at(j)){//
            	cnt++;
            }
        }
     	for(int j=0;j<M;j++){
			if(M_t.at(j)==N_s.at(i))cnt--;
    	}
      	if(i==0){
          	N_max=cnt;
        }
      	else if(cnt>N_max){
          	N_max = cnt;
        }
    }
  
  	for(int i=0;i<M;i++){//
      	int cnt = 0;
		for(int j=0;j<M;j++){//
        	if(M_t.at(i)==M_t.at(j)){//
            	cnt--;
            }
        }
     	for(int j=0;j<N;j++){
			if(N_s.at(j)==M_t.at(i))cnt++;
    	}
      	if(i==0){
          	M_max=cnt;
        }
      	else if(cnt>M_max){
          	M_max = cnt;
        }
    }
  	if(M_max > N_max)max = M_max;
  else max=N_max;
  	if(max<0)max = 0;
    cout << max << endl;
}
