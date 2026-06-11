#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int S;
    cin >> S;
    int x, y ;
    x = S /100;
    y = S % 100;
    if ( 1 <= x && x <= 12){
        if ( 1 <= y && y <= 12)cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }else{
        if(1 <= y && y <= 12) cout << "YYMM" <<endl;
        else cout << "NA" << endl;
    }
    return 0;
}