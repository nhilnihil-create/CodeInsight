#include <bits/stdc++.h>
using namespace std;

int	main(void)
{
  int time, price_p_hour, flat_rate;
  cin >> time >> price_p_hour >> flat_rate;
  if ((time * price_p_hour) > flat_rate)
    cout << flat_rate << endl;
  else if ((time * price_p_hour) == flat_rate)
    cout << flat_rate << endl;
  else
    cout << time * price_p_hour << endl;
}