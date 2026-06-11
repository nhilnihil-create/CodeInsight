//ABC126_Cのように関数でdouble型で返ってきてほしい場合はdouble kan_halfのようにかく
/*
//ABC_041_C// pair型
int main() {
  int n;
  cin >> n;
  vector<pair<int,int>>a(n);
  for(int i=0;i<n;i++){
    int num;
    cin >> num;
    a.at(i).first  = num;
    a.at(i).second = i;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(),a.end());
  for(int i=0;i<n;i++){
    cout << a.at(i).second + 1<< endl;
  }
}
*/
/*ABC_068_C //boolの配列を使って
bool s[200050] = {};
bool t[200050] = {};
int main() {
	ll n, m; cin >> n >> m;
	for (int i = 0; i < m; i++){
		ll a, b; cin >> a >> b;
		if (a == 1) {
			t[b] = true;
		}
		if (b == n) {
			s[a] = true;
		}
	}
	for (int i = 0; i < 200050; i++){
		if (s[i] && t[i]) {
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
*/

//int32	4	signed, signed int, int	-2,147,483,648 ～ 2,147,483,647 = 2*10^9
//再帰関数 ABC_029_C
/*
void f(int rest , string s){
  if(rest == 0){
    cout << s << endl;
  }
  else{
    for(char moji = 'a' ;moji <='c' ; moji++){
      f(rest-1,s+moji);
    } 
  }
}
 
int main() {
  int n;
  cin >> n;
  f(n, "");
}
*/
  //連想配列 ARC_081_Cの解答 //ABC073でも復習できます。
/*
int main() {
  ll n;
  cin >> n;
  vector<ll>a(n);
  rep(i,n) cin>>a.at(i);
  map<ll,ll>mp;
  rep(i,n){
    mp[a.at(i)]++;
  }
  ll one  = 0;
  ll two = 0;
  for(auto p:mp){
//    cout << p.first << " " << p.second << endl;
    if(p.second >= 2){
      if(one <= p.first){
        two = one;
        one = p.first;
      }
    }
    if(p.second >= 4){
      if(one <= p.first){
        two = p.first;
        one = p.first;
      }
    }
  }
//  cout << one << endl;
//  cout << two << endl;
//  cout << endl;
  cout << one * two << endl;
}
*/

//#define pi 3.14159265359
//桁数を指定して出力する方法
//#include <iomanip>//これをincludeしておかないといけない
//cout << fixed << setprecision(20)<< ans << endl;

//  s.at(0) = toupper(s.at(0));//小文字なら大文字へ//大文字の場合はそのまま
//  s.at(i) = tolower(s.at(i));//大文字なら小文字へ//小文字の場合はそのまま
//getline(cin, s); //空白文字を含むものをまとめて入力できる。
//s配列に格納した単語を、辞書順にソートする
//  sort(s.begin(), s.end());
//  string t = "keyence";//で文字列を格納できる
//s.empty() //emptyなら1を出力 入っていれば0を出力
/*//ABC018-B 部分的にreverseをかける解法
int main() {
  string s; cin >> s;
  int n; cin >> n;
  vector<int>a(n); vector<int>b(n);
  rep(i,n) cin>>a.at(i)>>b.at(i);
  rep(i,n)a.at(i)--;  rep(i,n)b.at(i)--;
  string t;
  rep(i,n){
    t = s;
    for(int k=0;k<=b.at(i)-a.at(i);k++){
      t.at(a.at(i)+k) = s.at(b.at(i)-k);
    }
    s = t;
  }
  cout << s << endl;
}
*///ABC018-B
//  cout << char(i+48) << endl;//なぜかaは47と得る時がある。+48で出力もaにできる。
//  cout << char(97) << endl;//アスキーコードでaを出力
// sort(b.begin(), b.end());//bという配列を小さい方からソート
// reverse(b.begin(), b.end());//bという配列をリターン
/*01 02 03 12 13 23　と６回見ていくパターン 
for(int i=0;i<n-1;i++){
  for(int j=i+1;j<n;j++){
    }
  }
*/
//vector<vector<int>> a(3, vector<int>(4));//int型の2次元配列(3×4要素の)の宣言
//10のi乗pow(10, i);//ただしdouble型のため注意
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
*/
#include <bits/stdc++.h>
#include <iomanip>//これをincludeしておかないといけない
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int gcd(ll a, ll b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b){
   return a * b / gcd(a, b);
}

int kan_hyaku(int n){
  int kurai = 0;
  for(int i=0;i<3;i++){
    kurai = n%10;
    n /=10;
  }
  return kurai;
}
int kan_ju(int n){
  int kurai = 0;
  for(int i=0;i<2;i++){
    kurai = n%10;
    n /=10;
  }
  return kurai;
}
int kan_ichi(int n){
  int kurai = 0;
  for(int i=0;i<1;i++){
    kurai = n%10;
    n /=10;
  }
  return kurai;
}

int keta(int n){
  int wa = 1;
  while(n>0){
    wa *=10;
    n--;
  }
  return wa;
}

double kan_half(int n){
  double wa = 1;
  while(n>0){
//    cout << "TEST"<<endl;
    wa *= 0.5;
//    cout << wa << endl;
    n--;
  }
  return wa;
}

int main() {
  double n;
  int k;
  cin >> n >> k;
  double sum = 0;
  for(int i=1;i<=n;i++){
    int count = 0;
    int num = i;  
    for(;;){
      if(k <= num) break;
      num *= 2;
      count ++;
    }
    double s = 1/n * kan_half(count);
    sum += s;
  }
  cout << fixed << setprecision(20)<< sum << endl;
}       