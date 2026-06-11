//Tariquzzaman Faisal
//_Faisal101_
//IUT_CSE'19
//190041101

#include<iostream>
#include<stdio.h>
#include<vector>
#include<deque>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
#include<iterator>
#include<set>
#define mp make_pair
#define pb push_back
#define pb push_back
#define fileOut freopen("out.txt","w",stdout)
#define fileIn freopen("in.txt","r",stdout)
#define testcases ll tc,t; cin >> tc; for(t=1; t<=tc; t++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define INFLL 9223372036854775807
#define INF 2147483647
#define ff first
#define ss second
#define pi acos(-1.0)
#define ll long long
#define endll printf("\n")

using namespace std;


int main(){
    string s;
    cin >> s;
    ll len = s.size();
    ll counter = 0, temp = 0;;
    for (ll i = 0; i < len; i++)
    {
        if(s[i] == 'A'){
            temp ++;
        }
        else if(s[i] == 'B'){
            if(i+1<len && s[i+1] =='C'){
                counter += temp;
                i++;
            }
            else{
                temp = 0;
            }
        }
        else{
            temp = 0;
        }
    }
    cout<<counter<<endl;
    
return 0;
}