#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,D;
    cin >> A >> B >> C >> D;
    int l,r;
    l = A + B;
    r = C + D;
    if(l<r){
    	cout << "Right" << endl;
    }
    else if(l>r){
    	cout << "Left" << endl;
    }
	else cout << "Balanced" << endl;  
}
