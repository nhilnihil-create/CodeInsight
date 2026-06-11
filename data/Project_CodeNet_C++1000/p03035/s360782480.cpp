#include <iostream>
#include <iomanip>
/*cout <<setprecision(11)<<ret<<endl;で、数字部分を計11桁表示*/
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Shift+Command+bでデバッグ
//その後ターミナルで./a.outを実行
//入力を貼り付ける

//////////////////
//  A
int main(void){
    int a,b;
    cin >>a>>b;
    if(a<=5) cout<< 0<<endl;
    else if(a<=12) cout<<(b/2)<<endl;
    else cout<<b<<endl;
    return 0;
}