#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

int main(){
    char c;
    int x=0,y=0;
    
    rep(i,4){
        cin >> c;
        if(i<2){
            x = x*10 + ctoi(c);
        }else{
            y = y*10 + ctoi(c);
        }
    }
    
    bool YYMM=false;
    if(1<=y && y<=12){
        YYMM=true;
    }
    
    bool MMYY=false;
    if(1<=x && x<=12){
        MMYY=true;
    }
    
    if(YYMM && MMYY){
        cout << "AMBIGUOUS" << endl;
    }else if(YYMM){
        cout << "YYMM" << endl;
    }else if(MMYY){
        cout << "MMYY" << endl;
    }else{
        cout << "NA" << endl;
    }
    
    
    //cout << "x:y " << x << ":" << y << endl;
}
