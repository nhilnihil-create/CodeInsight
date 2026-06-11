#include <iostream>
#include <iomanip>
/*cout <<setprecision(11)<<ret<<endl;で、数字部分を計11桁表示*/
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//Shift+Command+bでデバッグ
//その後ターミナルで./a.outを実行
//入力を貼り付ける

//////////////////
//  A
/*int main(void){
    int a,p;cin >>a >>p;
    cout<<(a*3+p)/2<<endl;

    return 0;
}*/
//////////////////
//  B
int main(void){
    int n;cin>>n;
    vector<pair<string,pair<int,int> > > box(n);

    rep(i,n){
        cin>>box[i].first>>box[i].second.first;
        box[i].second.second=i+1;
        box[i].second.first*=-1;
    }
    sort(box.begin(), box.end());

    //rep(i,n)cout <<box[i].first<<" "<<box[i].second.first<<" "<<box[i].second.second<<endl;

    rep(i,n) cout<<box[i].second.second<<endl;
    return 0;
}
//////////////////
//  C
/*int main(void){

    return 0;
}*/
//////////////////
//  D
/*int main(void){

    return 0;
}*/
//////////////////
//  E
/*int main(void){

    return 0;
}*/
//////////////////
//  F
/*int main(void){

    return 0;
}*/
