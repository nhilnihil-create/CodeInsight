#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    long long p;
  	cin >> n >> p ;
    long long root;
    long long r =2;
    root = sqrt(p);

    vector<long long> f;
    while(root>= r){
        if(p%r==0){
            f.push_back(r);
            p = p / r;
        }
        else{
            r += 1;
        }
    }
    if(p>2){
        f.push_back(p);
    }

/*	for(int i=0;i<f.size();i++){

        cout << f.at(i) << endl;
    }
*/
    long long answer = 1;
    long long now = 1;
    long long k = 0;
    for(long long i =0;i<f.size();i++){
        if(now==f.at(i)){
            k += 1;
        }
        else{
            answer = answer * pow(now , (k / n));
            now = f.at(i);
            k=1;
        }
    }
    answer = answer *  pow(now , (k / n));
    cout << answer << endl;
}


