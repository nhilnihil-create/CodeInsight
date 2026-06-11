#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int a,b,c,d,e,k;
    cin >>a>>b>>c>>d>>e>>k;
    int max_num,min_num;
    max_num = max(a,max(b,max(c,max(d,e))));
    min_num = min(a,min(b,min(c,min(d,e))));
    string ans = "Yay!";
    if(max_num - min_num > k){
        ans = ":(";
    }
    cout << ans << endl;
}
