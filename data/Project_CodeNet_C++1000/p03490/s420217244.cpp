#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <cstdlib>

bool find(std::vector<int> &m, int goal)
{
    std::set<int> cand, cand_n;
    cand.insert(0);
    for(auto v : m)
    {
        for(auto w : cand)
        {
            cand_n.insert(w+v);
            cand_n.insert(w-v);
        }
        cand.clear();
        cand.swap(cand_n);
    }
    return cand.find(goal) != cand.end();
}

int main(void)
{
    std::string commands;
    int x_goal, y_goal;
    std::cin >> commands >> x_goal >> y_goal;

    std::vector<int> xm;
    std::vector<int> ym;
    bool d_is_x = true;
    int distance = 0;
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
    bool xf = find(xm, x_goal);
    bool yf = find(ym, y_goal);        
    std::cout << (xf && yf ? "Yes" : "No") << std::endl;
    return 0;
}
