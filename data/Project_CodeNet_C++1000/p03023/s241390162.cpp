#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;
typedef vector <ll> v_ll;
typedef vector <vector <ll> > vv_ll;
typedef vector < pair <ll,ll> > vp_ll;
typedef pair <ll,ll> p_ll;

bool TEST=false;

void show(){
  if (TEST){cout << endl;}
}

void show(string x){
  if (TEST){cout << x;}
}

void show(string x,bool enter){
  if (TEST){
    if (enter) cout << "<#> " << x << endl;
    else cout << x;
  }
}

void show(ll x){
  if (TEST){cout << x;}
}

void show(ll x,bool enter){
  if (TEST){
    if (enter) cout << "<#> " << x << endl;
    else cout << x;
  }
}


void show(p_ll p){
  if (TEST){
    cout << "{ ";
    show(p.first);
    cout << " ";
    show(p.second);
    cout << " }";
  }
}

void show(v_ll v){
  if (TEST){
    cout << "<begin> ";
    for (ll i=0;i<v.size();i++){
      show(v[i]); cout << " ";
    }cout <<"<end>"<< endl;
  }
}

void show(vv_ll v){
  if (TEST){
    cout << "//////////" << endl;
    for (ll i=0;i<v.size();i++){
      show(v[i]); cout << endl;
    }
  }
}

void show(vp_ll v){
  if (TEST){
    cout << "//////////" << endl;
    for (ll i=0;i<v.size();i++){
      show(v[i]); cout << endl;
    }
  }
}

ll N;
int main(){
  cin >> N;
  cout << (N-2)*180 << endl;

}
