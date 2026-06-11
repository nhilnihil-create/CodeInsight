#include <bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{  
    LL N,M;
    cin >> N >> M;
    vector<pair<LL,LL>> d(N);

    for(int i=0; i<N ;i++){
        cin >> d.at(i).first >> d.at(i).second ;
    }

    sort(d.begin(),d.end());

    LL bill=0;
    LL cnt=0;
    int i=0;

    while(cnt < M){

        if(cnt + d.at(i).second > M ){
            bill += (M-cnt)*d.at(i).first;
            cnt += (M-cnt);
        }else{
            cnt += d.at(i).second;
            bill += d.at(i).first * d.at(i).second;
        }
        i++;
    }
    
    cout << bill << endl;
    return 0;
}