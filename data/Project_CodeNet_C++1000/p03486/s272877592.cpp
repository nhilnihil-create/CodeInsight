#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
using namespace std;


int main(void){
    string A,B;
    cin >> A;
    cin >> B;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(),std::greater<char>());
    if(A < B){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}   