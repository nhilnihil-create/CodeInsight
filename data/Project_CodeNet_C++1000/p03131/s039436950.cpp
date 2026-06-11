#include <bits/stdc++.h>
using namespace std;

int main()
{


    int64_t k,a,b;
    cin>>k>>a>>b;

    //交換しない方がよい場合
    if(a+2>b||k<(a-1)+2)
        cout<<k+1<<endl;
    else{
        //1回交換してb枚にする、+kから初回1回分を引いたのが残り、それを交換コスト2で割って1回ごとに(b-a)増える。それと余り
        int64_t wk1=b+(k-(a-1)-2)/2*(b-a)+(k-(a-1)-2)%2;
        cout<<wk1<<endl;
    }


    return 0;
}
