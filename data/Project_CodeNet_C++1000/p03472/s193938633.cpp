#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
long long n , monster , pos, lempar[200000] , attacks , a;
pair<int , int>katana[200000];

int main(){
	cin >> n >> monster;
	for(int i = 1 ; i <= n ; i++){
		cin >> katana[i].fi >> katana[i].se;
 	}
 	sort(katana + 1 , katana + n + 1);
 	for(int i = n ; i >= 1 ; i--){
 		if(katana[i].fi != katana[i - 1].fi){
 			pos = i;
 			break;
		 }
	 }
 	for(int i = n ; i >= 1 ; i--){
 		if(i == pos || katana[pos].fi >= katana[i].se)continue;
 		a++;
 		lempar[a] = katana[i].se;
	}
	sort(lempar + 1 , lempar + a + 1);
	lempar[0] = 0;
	for(int i = a ; i >= 1 ; i--){
		attacks++;
		if(monster - katana[pos].se <= 0){
			cout << attacks << endl;
			return 0;
		}
		monster -= lempar[i];
		if(monster <= 0){
			cout << attacks << endl;
			return 0;
		}
	}
	monster -= katana[pos].se;
	attacks++;
	if(monster <= 0){
		cout << attacks << endl;
		return 0;
	}
	attacks += monster/katana[pos].fi;
	if(monster % katana[pos].fi != 0)attacks++;
	cout << attacks << endl;
}