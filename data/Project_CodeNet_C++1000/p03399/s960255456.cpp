/**
 * Author  : dhakad_123
 * Created : 15.08.2020
 **/

#include<bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int A , B , C , D;

	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;

	
	cout << min(A , B) + min(C , D) << endl;


       return 0;

}
