#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    //input
    int N,M;
    map<string, int> jisho;
    int i;
    string s;
    cin >> N;
    for(i=0; i<N; i++){
        cin >> s;
        jisho[s]++;
    }
    cin >> M;
    for(i=0; i<M; i++){
        cin >> s;
        jisho[s]--;
    }

    //calc
    int ans=0;
    for(auto p: jisho){
        ans=max(ans,p.second);
    }


    //output
    cout << ans << endl;
    system("pause");
    return 0;
}