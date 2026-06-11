#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>

int main(void)
{
    std::string commands;
    short x_goal, y_goal;
    std::cin >> commands >> x_goal >> y_goal;

    std::vector<short> xm;
    std::vector<short> ym;
    bool d_is_x = true;
    short distance = 0;
    bool first_x = true;
    commands += 'T';
    for(int i=0; i<commands.size(); ++i)
    {
        if(commands[i] == 'T')
        {
            if(d_is_x)
            {
                if(first_x)
                {
                    x_goal -= distance;
                    first_x = false;
                }
                else
                    xm.push_back(distance);
            }
            else
                ym.push_back(distance);
            distance = 0;
            d_is_x = !d_is_x;
        }
        else // F
            ++distance;
    }
    std::sort(xm.begin(), xm.end(), std::greater<short>());
    std::sort(ym.begin(), ym.end(), std::greater<short>());
    for(auto v : xm)
    {
        if(abs(x_goal+v) > abs(x_goal-v))
            x_goal -= v;
        else
            x_goal += v;
    }
    for(auto v : ym)
    {
        if(abs(y_goal+v) > abs(y_goal-v))
            y_goal -= v;
        else
            y_goal += v;
    }
    std::cout << (x_goal == 0 && y_goal == 0 ? "Yes" : "No") << std::endl;
    return 0;
}
