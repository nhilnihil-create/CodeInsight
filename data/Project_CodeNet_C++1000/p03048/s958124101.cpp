#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main() {

	int R,G,B,N;
	cin >> R >> G >> B >> N;
	
	long long cnt=0;
	for(int r=0;r<=3000/R;r++){
		for(int g=0;g<=3000/G;g++){
			long long x=r*R+g*G;
			if(N>=x && (N-x)%B==0){
				cnt++;
				//break;
			}
		}
	}
    cout << cnt << endl;
	return 0;
}
