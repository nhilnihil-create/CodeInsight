#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        a.push_back(b);
    }

    sort(a.begin(),a.end());

    int min=a.at(0)+1;
    int atk=0;
    int tmp=a.at(0);
    while(tmp<min){
        min=tmp;    
        for(int i=0;i<a.size();i++){
            if(a.at(i)==0) continue;
            if(i!=atk){
                a.at(i)=a.at(i)%min;
                if(0<a.at(i) && a.at(i)<min){
                    atk=i;
                    tmp=a.at(i);
                    break;
                }
            }
        }
    }

    cout << min << endl;
}