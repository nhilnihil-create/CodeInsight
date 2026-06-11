#include<iostream>
#include<string>

using namespace std;

int main(){
    //真ん中の方は反転の時に必ず同じ動きをする．真ん中以外は自由に動ける(要検証)ので，真ん中がどれだけ同じ符号か？を調べれば良い．
    string str;
    cin>>str;
    int N=str.size();
    int count=0;
    char key=str[N/2];
    int right=(N+1)/2;
    int left=N/2-1;
    while(str[right]==key && str[left]==key){
        right++;
        left--;
        count++;
        if(left<0) break;
    }
    int ans=count+(N+1)/2;
    cout<<ans<<endl;
    return 0;
}
