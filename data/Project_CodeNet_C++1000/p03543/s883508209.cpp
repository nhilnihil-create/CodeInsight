#include <bits/stdc++.h>
using namespace std;

int main() {
	int N ;
  	cin >> N ;
  	int Sen , Hyaku , Ju , Ichi ;
    Sen = N / 1000 ;
    N = N % 1000 ;
    Hyaku = N / 100 ;
    N = N % 100 ;
    Ju = N / 10 ;
    N = N % 10;
    Ichi = N ;
    if(Sen == Hyaku && Hyaku == Ju){
    	cout << "Yes" << endl;
    }else if(Hyaku == Ju && Ju == Ichi){
        cout << "Yes" << endl;
    }else{
    	cout << "No" << endl;
    }
}
