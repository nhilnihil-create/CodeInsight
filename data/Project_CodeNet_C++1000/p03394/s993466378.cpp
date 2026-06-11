#include <iostream>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n==3){
        cout << "2 3 25" << endl;
        return 0;
    }
    set<int> st2,st3,st6,ans;
    ans.insert(2);
    ans.insert(4);
    ans.insert(3);
    ans.insert(9);
    st6.insert(6);
    st2.insert(8);
    for(int i = 10;i<=30000;i++){
        if(i%6==0) st6.insert(i);
        else if(i%2==0) st2.insert(i);
        else if(i%3==0) st3.insert(i);
    }
    int k = min(2*((n-4)/4),4990);
    int t = n-2*k-4;
    int cnt = 0;
    if(n>=15000){
        for(auto itr = st2.begin();itr!=st2.end();itr++) ans.insert(*itr);
        for(auto itr = st3.begin();itr!=st3.end();itr++) ans.insert(*itr);
        for(auto itr = st6.begin();itr!=st6.end();itr++){
            if(cnt==n-15000) break;
            ans.insert(*itr);
            cnt++;
        }
    }
    else{
        auto itr1 = st2.begin();
        auto itr2 = st3.begin();
        for(int i = 0;i<k;i++){
            ans.insert(*itr1);
            ans.insert(*itr2);
            itr1++;
            itr2++;
        }
        for(int i = 0;i<t;i++){
            ans.insert(6*(i+1));
        }
    }
    for(auto itr = ans.begin();itr!=ans.end();itr++){
        cout << *itr << " ";
    }
}