#include <bits/stdc++.h>
using namespace std;
long long ta[399999];

int main()
{
    long long n;
  	cin >> n;
    vector<long long> l(n);
    vector<long long> r(n);
    long long i;
    for(i=0;i<n;i++){
        cin >> l.at(i) >> r.at(i);

    }

    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    long long answer=0;
    long long now = 0;
    for(i=0;i<n;i++){
        if(r.at(i) < now){
            answer += (now - r.at(i) );
            now = r.at(i);
//            cout << now <<endl;
        }else{
            answer += abs(now);
            break;
        }
        if(l.at(n-i-1) > now){
            answer += (l.at(n-i-1) - now);
            now = l.at(n-i-1);
//            cout << now <<endl;
        }else{
            answer += abs(now);
            break;
        }
    }
    long long ans1 = answer;
    answer =0;
    now = 0;
for(i=0;i<n;i++){
        if(l.at(n-i-1) > now){
            answer += (l.at(n-i-1) - now);
            now = l.at(n-i-1);
//            cout << now <<endl;
        }else{
            answer += abs(now);
            break;
        }
        if(r.at(i) < now){
            answer += (now - r.at(i) );
            now = r.at(i);
//            cout << now <<endl;
        }else{
            answer += abs(now);
            break;
        }
    }
    long long ans2 = answer;
    answer = ans1 < ans2 ? ans2 : ans1;
    cout << answer ;
}