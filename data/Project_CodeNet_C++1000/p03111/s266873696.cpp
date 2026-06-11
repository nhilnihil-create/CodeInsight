#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int infty = (1 << 21);



int make_bamboo(vector<int> &assign,vector<int> &array,vector<int> &abc,vector<int> &use){
    ll mp = 0;
    vector<int> a,b,c;
    for(int i=0;i<assign.size();i++){
        if(assign.at(i) == 0){
            a.push_back(i);
        }else if(assign.at(i) == 1){
            b.push_back(i);
        }else{
            c.push_back(i);
        }
    }

    if(a.size() == 0 || b.size() == 0|| c.size() == 0) return infty;
    int a_bamboo = use.at(a.at(0));
    for(int i=1;i<a.size();i++){
        mp += 10;
        a_bamboo += use.at(a.at(i));
    }
    mp += abs(abc.at(0) - a_bamboo);

    int b_bamboo = use.at(b.at(0));
    for(int i=1;i<b.size();i++){
        mp += 10;
        b_bamboo += use.at(b.at(i));
    }
    mp += abs(abc.at(1) - b_bamboo);

    int c_bamboo = use.at(c.at(0));
    for(int i=1;i<c.size();i++){
        mp += 10;
        c_bamboo += use.at(c.at(i));
    }
    mp += abs(abc.at(2) - c_bamboo);
    //cout << mp << endl;
    return mp;

}

int func(vector<int> &array,vector<int> &use,vector<int> &abc){
    int minmp = infty;
    int n = use.size();
    for(int tmp = 0; tmp < pow(3,n); tmp++){
        int mark = tmp;
        vector<int> assign(n);
        for(int i=n-1;i>=0;i--){
            int a = pow(3,i);
            assign.at(i) = mark / a;
            mark = mark % a;
        }
        int mp = make_bamboo(assign,array,abc,use);
        if(minmp > mp) minmp = mp;
    }
    return minmp;
}


int main(){
    int n,a,b,c,minmp = infty;
    cin >> n ;
    vector<int> abc(3);
    for(int i=0;i<3;i++) cin >> abc.at(i);
    vector<int> array(n);
    for(int i=0;i<n;i++) cin >> array.at(i);
    for(int tmp=0; tmp < (1 << n); tmp++){
        vector<int> use(0);
        bitset<8> s(tmp);
        for(int i=0;i<n;i++){
            if(s.test(i)){
                use.push_back(array.at(i));
                int mp = func(array,use,abc);
                if(mp < minmp) minmp = mp;
            }

        }
    }
    cout << minmp << endl;
}