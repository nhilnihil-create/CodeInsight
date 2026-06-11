#include <bits/stdc++.h>
using namespace std;

int main(){
	int D, G;
	cin >> D >> G;
	vector<int> p(D), c(D);
	for(int i=0; i<D; i++){
		cin >> p.at(i) >> c.at(i);
	}

	long long score;
	int cnt;
	int mincnt=1000;
	for(int i=0; i<( 1<<10 ); i++){
		bitset<10> bit(i);
		score=0;
		cnt=0;
		for(int j=0; j<D; j++){
			if( bit.test(j) == 1 ){
				cnt += p.at(j);
				score +=p.at(j) *100*(j+1)+c.at(j);
			}
		}
		if( score >= G ){
			if( mincnt > cnt ){
				mincnt = cnt;
			}
		}
		else{
			for(int j=D-1; j>-1; j--){
				if( bit.test(j) == 0 ){
					for(int k=0; k<p.at(j)-1; k++){
						cnt++;
						score += 100*(j+1);
						if( score >= G ){
							if( mincnt > cnt ){
								mincnt = cnt;
							}
						}
					}
				break;
				}
			}
			
		}
		if( i == pow(2,D)-1) break;
	}
	cout << mincnt << endl;
}
