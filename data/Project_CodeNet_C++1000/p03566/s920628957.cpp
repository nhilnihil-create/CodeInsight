#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>

using namespace std;

typedef pair<int, int> Line;
typedef pair<double, double> Point;

//y = ax + b
Line make_line(int x, int y, int kind){
  int a = kind == 0 ? 1 : -1;
  int b = y - a * x;
  Line result = {a, b};
  return result;
}

//fとgの交点を計算
Point calc_cross_point(Line f, Line g)
{
  double x = double(g.second - f.second) / double(f.first - g.first);
  double y = x * f.first + f.second;
  return {x, y};
}

Point calc_cross_point(Line f, double y)
{
  double x = (y - f.second) / double(f.first);
  return {x, y};
}

//積分関数
double integral(Line target, double from, double to)
{
  double f_from = target.first * from + target.second;
  double f_to = target.first * to + target.second;
  double f_ave = target.first * ((from + to) / 2.0) + target.second;
  double result = ((to - from) / 6.0) * (f_from + 4.0 * f_ave + f_to);
  return result;
}

//面積計算関数
double get_area(Line plus, Line minus, int v, int t1, int t2)
{
  Point cross_point = calc_cross_point(plus, minus);
  double area = 0.0;
  if(cross_point.second > v)
  {
    //台形になる
    Point top_left = calc_cross_point(plus, v);
    Point top_right = calc_cross_point(minus, v);
    area = integral(plus, t1, top_left.first);
    area += integral(minus, top_right.first, t2);
    area += (top_right.first - top_left.first) * v;
  }else{
    //三角形
    area = integral(plus, t1, cross_point.first);
    area += integral(minus, cross_point.first, t2);
  }
  return area;
}

int main()
{
  /*int n;
  cin >> n;
  vector<int> t(n + 1);
  vector<int> v(n + 2);
  for(int i = 1; i <= n; i++)
  {
    cin >> t[i];
    t[i] = t[i] + t[i - 1];
  }
  for(int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }
  t[0] = v[0] = 0;
  v[v.size() - 1] = 0;

  double result = 0.0;
  for(int i = 0; i < n; i++)
  {
    Line plus = make_line(t[i], min(v[i], v[i + 1]), 0);
    Line minus = make_line(t[i + 1], min(v[i + 1], v[i + 2]), 1);

    Point cross_point = calc_cross_point(plus, minus);

    double area = 0.0;
    if(cross_point.second > v[i + 1])
    {
      //台形になる
      Point top_left = calc_cross_point(plus, v[i + 1]);
      Point top_right = calc_cross_point(minus, v[i + 1]);
      area = integral(plus, t[i], top_left.first);
      area += integral(minus, top_right.first, t[i + 1]);
      area += (top_right.first - top_left.first) * v[i + 1];
    }else{
      //三角形
      area = integral(plus, t[i], cross_point.first);
      area += integral(minus, cross_point.first, t[i + 1]);
    }
    result += area;
  }
  cout << fixed;
  cout << setprecision(4);
  cout << result << endl;
	return 0;*/
  int n;
  cin >> n;
  vector<int> t(n + 1, 0);
  vector<int> v(n + 1, 0);
  for(int i = 1; i <= n; i++)
  {
    cin >> t[i];
    t[i] = t[i] + t[i - 1];
  }
  for(int i = 1; i <= n; i++)
  {
    cin >> v[i];
  }
  vector<vector<double>> dp(n + 1, vector<double>(101, -1));
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j <= 100; j++)
    {
      //区間iを速度jで走り終わった際の最高走行距離でdp
      double max_s = -1.0;
      for(int k = 0; k <= 100; k++)
      {
        double area = 0.0;
        if(abs(k - j) > t[i] - t[i - 1]){
          continue;
        }else if(k > v[i] || j > v[i])
        {
          continue;
        }else if(dp[i - 1][k] == -1)
        {
          continue;
        }else{
          Line plus = make_line(t[i - 1], k, 0);
          Line minus = make_line(t[i], j, 1);
          area = get_area(plus, minus, v[i], t[i - 1], t[i]) + dp[i - 1][k];
        }
        max_s = max(area, max_s);
      }
      dp[i][j] = max_s;
    }
  }
  cout << fixed << setprecision(15) << dp[n][0] << endl;
}
