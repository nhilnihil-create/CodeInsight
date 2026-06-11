#include <bits/stdc++.h>
using namespace std;

int main() {
	int time=0;
	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;
	int N=5;
	
	vector <int> Time={A, B, C, D, E};
	vector <int> index={0, 1, 2, 3, 4};
	
	int bestTime=(int)1e9;
	do{
	    int Nowtime=0;
	    for (int i=0; i<N; i++){
	        while (Nowtime%10!=0) Nowtime++;
	        Nowtime+=Time[index[i]];
	    }
	    bestTime=min(bestTime, Nowtime);
	} while (next_permutation(index.begin(), index.end()));
	cout << bestTime << endl;
}