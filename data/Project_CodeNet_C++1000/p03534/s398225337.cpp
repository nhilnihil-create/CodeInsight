#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string S;
vector<int> C(3,0);

int main(){
	cin >> S;
	int N = S.size();
	if(N==1) cout << "YES" << endl;
	else{
		for(int i=0;i<N;i++){
			C[S[i]-'a']++;
		}
		sort(C.begin(),C.end());
		reverse(C.begin(),C.end());
		if(N==2){
			if(C[1]==0) cout << "NO" << endl;
			else cout << "YES" << endl;
		}else{
			if(C[2]==0) cout << "NO" << endl;
			else{
				if(C[0]==C[1] && C[1]==C[2]) cout << "YES" << endl;
				else if(C[0]==C[1]){
					if(C[1]==C[2]+1) cout << "YES" << endl;
					else cout << "NO" << endl;
				}else if(C[1]==C[2] && C[0] == C[1]+1) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}
	}
}