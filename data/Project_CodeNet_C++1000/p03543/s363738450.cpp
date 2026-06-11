#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
    cin >> N;
    if(N%1111 == 0){
    	cout << "Yes" << endl;
    }
    else if((N/10)%111==0){
    	cout << "Yes" << endl;
    }
    else if((N%1000)%111==0){
    	cout << "Yes" << endl;
    }
    else{
    	cout << "No" << endl;
    }
}
