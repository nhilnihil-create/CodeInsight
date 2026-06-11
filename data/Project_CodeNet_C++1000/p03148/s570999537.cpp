


#include "bits/stdc++.h"
#include <random>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef string ST;


#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) for(auto (a): v )   cerr << a << endl
#define PRINTSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl

void func() {
  LL N, K;
  cin >> N >> K;


  // ネタごとに美味しい順に並べる
  map<LL, priority_queue<LL>> S;
  for (LL i = 0; i < N; ++i) {
    LL t, d;
    cin >> t >> d;
    S[t].push(d);
  }

  vector<LL> y1;
  vector<LL> y0;
  for (auto s : S) {
    y1.push_back(s.second.top());
    s.second.pop();
    while (!s.second.empty()) {
      y0.push_back(s.second.top());
      s.second.pop();
    }
  }

  sort(ALL(y1), greater<LL>());
  sort(ALL(y0), greater<LL>());

  //cerr << "y1 : ";
  //for (auto y : y1) {
  //  cerr << y << " ";
  //}
  //cerr << endl;
  //cerr << "y0 : ";
  //for (auto y : y0) {
  //  cerr << y << " ";
  //}
  //cerr << endl;

  // 累積和
  vector<LL> cy1(y1.size());
  vector<LL> cy0(y0.size());
  if (y1.size() > 0) {
    cy1[0] = y1[0];
  }
  for (LL i = 1; i < y1.size(); ++i) {
    cy1[i] = cy1[i - 1] + y1[i];
  }
  if (y0.size() > 0) {
    cy0[0] = y0[0];
  }
  for (LL i = 1; i < y0.size(); ++i) {
    cy0[i] = cy0[i - 1] + y0[i];
  }
  //cerr << "cy1 : ";
  //for (auto y : cy1) {
  //  cerr << y << " ";
  //}
  //cerr << endl;
  //cerr << "cy0 : ";
  //for (auto y : cy0) {
  //  cerr << y << " ";
  //}
  //cerr << endl;





  LL manzoku_max = 0;
  for (LL i = 1; i <= K; ++i) {
    //! i種類のネタを食べる
    //!  y1からi個、y0からK-i個取る

    if (i > cy1.size()) {
      continue;
    }
    if ((K - i) > cy0.size()) {
      continue;
    }

    LL bonus = i * i;
    LL base = 0;
    if (i - 1 >= 0) {
      base += cy1[i - 1];
    }
    if (K - i - 1 >= 0) {
      base += cy0[K - i - 1];
    }
    LL manzoku = base + bonus;
    manzoku_max = max(manzoku_max, manzoku);
    //cerr << i << " : " << manzoku <<" : "<<base << " : " << bonus <<  endl;

  }
  cout << manzoku_max << endl;

}

void func_TLE2() {
  LL N, K;
  cin >> N >> K;


  // ネタごとに美味しい順に並べる
  map<LL, priority_queue<LL>> S;
  for (LL i = 0; i < N; ++i) {
    LL t, d;
    cin >> t >> d;
    S[t].push(d);
  }

  vector<LL> y1;
  vector<LL> y0;
  for (auto s : S) {
    y1.push_back(s.second.top());
    s.second.pop();
    while (!s.second.empty()) {
      y0.push_back(s.second.top());
      s.second.pop();
    }
  }

  sort(ALL(y1), greater<LL>());
  sort(ALL(y0), greater<LL>());


  //cerr << "y1 : ";
  //for (auto y : y1) {
  //  cerr << y << " ";
  //}
  //cerr << endl;
  //cerr << "y0 : ";
  //for (auto y : y0) {
  //  cerr << y << " ";
  //}
  //cerr << endl;


  LL manzoku_max = 0;
  for (LL i = 1; i <= K; ++i) {
    //! i種類のネタを食べる
    //!  y1からi個、y0からK-i個取る

    if (i > y1.size()) {
      continue;
    }
    if ((K - i) > y0.size()) {
      continue;
    }

    LL bonus = i * i;
    LL base = 0;
    auto tmp_y1 = y1;
    // y1からi個とる
    for (LL j = 0; j < i; ++j) {
      base += y1[j];
    }
    // y0からK-i個とる
    auto tmp_y0 = y0;
    for (LL j = 0; j < (K - i); ++j) {
      base += y0[j];
    }
    LL manzoku = base + bonus;
    manzoku_max = max(manzoku_max, manzoku);
    //cerr << i << " : " << manzoku <<" : "<<base << " : " << bonus <<  endl;

  }
  cout << manzoku_max << endl;

}








void func_TLE() {
  LL N, K;
  cin >> N >> K;


  // ネタごとに美味しい順に並べる
  map<LL, priority_queue<LL>> S;
  for (LL i = 0; i < N; ++i) {
    LL t, d;
    cin >> t >> d;
    S[t].push(d);
  }

  priority_queue<LL> y1;
  priority_queue<LL> y0;
  for (auto s : S) {
    y1.push(s.second.top());
    s.second.pop();
    while (!s.second.empty()) {
      y0.push(s.second.top());
      s.second.pop();
    }
  }

  //cerr << "y1 : ";
  //auto tmp = y1;
  //while (!tmp.empty()) {
  //  cerr << tmp.top() << " ";
  //  tmp.pop();
  //}
  //cerr << endl;
  //cerr << "y0 : ";
  //tmp = y0;
  //while (!tmp.empty()) {
  //  cerr << tmp.top() << " ";
  //  tmp.pop();
  //}
  //cerr << endl;

  LL manzoku_max = 0;
  for (LL i = 1; i <= K; ++i) {
    //! i種類のネタを食べる
    //!  y1からi個、y0からK-i個取る

    if (i > y1.size()) {
      continue;
    }
    if ((K - i) > y0.size()) {
      continue;
    }

    LL bonus = i * i;
    LL base = 0;
    auto tmp_y1 = y1;
    // y1からi個とる
    for (LL j = 0; j < i; ++j) {
      base += tmp_y1.top();
      tmp_y1.pop();
    }
    // y0からK-i個とる
    auto tmp_y0 = y0;
    for (LL j = 0; j < (K - i); ++j) {
      base += tmp_y0.top();
      tmp_y0.pop();
    }
    LL manzoku = base + bonus;
    manzoku_max = max(manzoku_max, manzoku);
    //cerr << i << " : " << manzoku <<" : "<<base << " : " << bonus <<  endl;

  }
  cout << manzoku_max << endl;

}








#ifdef CALC_TIME 
#include <windows.h>
int main()
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  LARGE_INTEGER start, end;
  QueryPerformanceCounter(&start);
  // 何かの処理
  func();
  QueryPerformanceCounter(&end);
  double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
  fprintf(stderr, "\n%lf[ms]\n", time);
  return 0;
}
#else 
int main()
{
  func();
  return 0;
}
#endif



