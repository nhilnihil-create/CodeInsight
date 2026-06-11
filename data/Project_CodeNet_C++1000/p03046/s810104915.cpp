#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll M, K;

/*
    M==0, M==1の場合
      ？
    
    
    Mが2以上の場合
    2**M未満の全ての数のXORすると 0 になる
    
    Kが0の場合
      a,b,c, ... ... c,b,a の形
    
    Kが0でない場合
     全ての数を、以下の3つに分ける
       K
       A, B : XORしてKになる組み合わせ  A^B=K && A != B && A != K && B != K
       a,b,c.. : 残り
     
     K^A^B == 0
     a^b^c^... = 0
    
     a,b,c.. A B ..c,b,a K B A K
      の形にする
    
    
    
*/

int main(){
	cin >> M >> K;
	
	if ( M == 0 ){
		if ( K == 0 )
			cout << "0 0" << endl;
		else
			cout << -1 << endl;
	}
	else if ( M == 1 ){
		if ( K == 0 )
			cout << "0 0 1 1" << endl;
		else
			cout << -1 << endl;
	}
	else {
		ll max = 1<<M;
		if ( K == 0 ){
			for ( ll i = 0; i < max; i++ ){
				cout << i << " ";
			}
			for ( ll i = max-1; i >= 0; i-- ){
				cout << i << " ";
			}
		}
		else if ( max <= K ){
			cout << -1 << endl;
		}
		else {
			ll A, B;
			A = 1;
			B = K ^ A;
			if ( B == 0 ){
				A = 2;
				B = K ^ A;
			}
			
			//  a,b,c.. A B ..c,b,a K B A K
			for ( ll i = 0; i < max; i++ ){
				if ( i != A && i != B && i != K )
					cout << i << " ";
			}
			cout << A << " " << B << " ";
			for ( ll i = max-1; i >= 0; i-- ){
				if ( i != A && i != B && i != K )
					cout << i << " ";
			}
			cout << K << " " << B << " " << A << " " << K << endl;
		}
	}
	
	return 0;
}

